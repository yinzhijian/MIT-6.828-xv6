	.text

/* Switch from current_thread to next_thread. Make next_thread
 * the current_thread, and set next_thread to 0.
 * Use eax as a temporary register; it is caller saved.
 */
	.globl thread_switch
thread_switch:
	/* YOUR CODE HERE */
    //save current thread reg
    movl current_thread,%eax
    pushal
    movl %esp,(%eax)
    //pop next thread reg
    movl next_thread,%eax
    movl (%eax),%esp
    popal
    //change current to next
    movl next_thread,%eax
    movl %eax,current_thread
	ret				/* pop return address from stack */
