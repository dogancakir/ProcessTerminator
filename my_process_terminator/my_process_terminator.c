#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/types.h>


asmlinkage long sys_my_process_terminator(pid_t pid, int flag)
{
	if(current->cred->euid != 0) 
	{
		printk("It does not supply root privilege!!! \n");
		return 1;
	}
	struct list_head *p, *p2;
	struct task_struct ts, ts2, *tsk, *tsk2;
	pid_t tmp_pid,tmp2_pid;
	INIT_LIST_HEAD(&ts.children);
	if(flag == 0)
	{
		tsk = pid_task(find_vpid(pid),PIDTYPE_PID);
		list_for_each(p,&(tsk->children))
		{
			ts = *list_entry(p, struct task_struct, sibling);
			tmp_pid = ts.pid;
			printk("Dead Child of Given PID: %d\n",tmp_pid);
			sys_kill(tmp_pid,SIGKILL);
		}
	}
	if(flag == 1)
	{
		tsk = pid_task(find_vpid(pid),PIDTYPE_PID);
		list_for_each(p,&(tsk->children))
		{
			ts = *list_entry(p, struct task_struct, sibling);
			tmp_pid = ts.pid;
			printk("Dead Child of Given PID: %d\n",tmp_pid);
			sys_kill(tmp_pid,SIGKILL);
		}
		
		tsk2 = tsk->real_parent;
		tmp2_pid=tsk2->pid;
			
		list_for_each(p, &(tsk2->children))
		{
			ts = *list_entry(p, struct task_struct, sibling);
			tmp_pid = ts.pid;
		
			if(tmp_pid!=pid)
			{
				tsk = pid_task(find_vpid(tmp_pid),PIDTYPE_PID);
				
				list_for_each(p2, &(tsk->children))
				{
					ts2= *list_entry(p2, struct task_struct, sibling);
					tmp2_pid = ts2.pid;
					printk("Dead Child of Sibling of Given Process: %d\n", tmp2_pid);
					sys_kill(tmp2_pid,SIGKILL);
				}
				printk("Sibling of Given Process: %d\n", tmp_pid);
				sys_kill(tmp_pid,SIGKILL);
					
			}
		}
		
		
	}
	return 0;
}
