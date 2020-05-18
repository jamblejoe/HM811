#!/usr/bin/perl

# example output from /stat/proc for a 4 core processor
# we are interested in the first line
#cpu  8856120 0 5360251 84510393 0 368470 0 0 0 0
#cpu0 1968570 0 1634562 21078559 0 305381 0 0 0 0
#cpu1 2422615 0 1350237 20908839 0 27509 0 0 0 0
#cpu2 2170915 0 1173209 21337567 0 19051 0 0 0 0
#cpu3 2294020 0 1202243 21185428 0 16529 0 0 0 0
#intr 894498 377553 332 0 0 0 0 0 0 0 287178 0 0 [... lots more numbers ...]
#ctxt 494453
#btime 1588591031
#processes 268
#procs_running 1
#procs_blocked 0
#softirq 531871 0 166655 5588 285920 8660 0 272 0 791 63985

open(FILE, "/proc/stat") || die "Could not open /proc/stat";
while(<FILE>) {
		next unless /^cpu\s/;
		my @cpu_times = split /\s+/, $_;
		shift @cpu_times;
		foreach (@cpu_times) {$last_total_cpu_time += $_}
		$last_idle_cpu_time = $cpu_times[3];
	}
	sleep 1;
close(FILE);

while(){
	open(FILE, "/proc/stat") || die "Could not open /proc/stat";
	while(<FILE>) {
		next unless /^cpu\s/;
		my @cpu_times = split " ", $_;
		shift @cpu_times;
		my $total_cpu_time = 0;
		foreach (@cpu_times) {$total_cpu_time += $_}
		my $idle_cpu_time = $cpu_times[3];
		my $total_cpu_delta = $total_cpu_time-$last_total_cpu_time;
		my $idle_cpu_delta = $idle_cpu_time-$last_idle_cpu_time;
		my $used_cpu_delta = $total_cpu_delta - $idle_cpu_delta;
		my $cpu_load = 100 * $used_cpu_delta/$total_cpu_delta;
		
		$last_total_cpu_time = $total_cpu_time;
		$last_idle_cpu_time = $idle_cpu_time;

		printf "%.0f\n", "$cpu_load";
	}
	close(FILE);
	sleep 1;
}
