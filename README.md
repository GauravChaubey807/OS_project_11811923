# OS_project_11811923
Operating System Project


# Question
Sudesh Sharma is a Linux expert who wants to have an online system where he can handle student queries. Since there can be multiple requests at any time he wishes to dedicate a fixed amount of time to every request so that everyone gets a fair share of his time. He will log into the system from 10am to 12am only. He wants to have separate requests queues for students and faculty. Implement a strategy for the same. The summary at the end of the session should include the total time he spent on handling queries and average query time.


# Objective
To make two queues with round robin scheduling for faculty and students so that Mr. Sudesh can give them equal amount of his time.


# Round Robin Scheduling
Round Robin is a CPU scheduling algorithm where each process is assigned a fixed time slot in a cyclic way. The fixed time slot is known as time quantum.

-It is simple, easy to implement, and starvation-free as all processes get fair share of CPU.
-One of the most commonly used technique in CPU scheduling as a core.
-It is preemptive as processes are assigned CPU only for a fixed slice of time at most.
-The disadvantage of it is more overhead of context switching.


# Terms and Formulas
1. **Completion Time:** Time at which process completes its execution.
2. **Turn Around Time:** Time Difference between completion time and arrival time. Turn Around Time = Completion Time – Arrival Time
3. **Waiting Time(W.T):** Time Difference between turn around time and burst time.
4. **Waiting Time = Turn Around Time – Burst Time**


# Pseudo Code
1. Create an array rem_bt[] to keep track of remaining
   burst time of processes. This array is initially a 
   copy of bt[] (burst times array)
2. Create another array wt[] to store waiting times
   of processes. Initialize this array as 0.
3. Initialize time : t = 0
4. Keep traversing the all processes while all processes
   are not done. Do following for i'th process if it is
   not done yet.
   -If rem_bt[i] > quantum
      -t = t + quantum
      - bt_rem[i] -= quantum;
   -Else // Last cycle for this process
      -t = t + bt_rem[i];
      -wt[i] = t - bt[i]
      -bt_rem[i] = 0; // This process is over
