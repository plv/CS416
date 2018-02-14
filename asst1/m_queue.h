#include "data_structure.h"
#include <sys/ucontext.h>

typedef enum State {
    Running,
    Ready,
    Terminated,
    Waiting,
    Locking
} state_t;

typedef struct threadControlBlock {
    int id;
    int p_level;
    ucontext_t context;
    state_t state;
    void * retval; // supplied to pthread_exit
} tcb;

tcb * tcb_init();

typedef struct multiLevelQueue {
    queue ** q_arr;
    int num_levels;
    int interval_time_delta;
    int size;
    int base_time;
} multi_queue;

multi_queue * m_queue_init(int num_levels, int time_delta, int base_time);
void init_job(void * element, multi_queue * m_q);
void * get_next_job(multi_queue * m_q);
int is_empty_m_queue(multi_queue * m_q);
int get_interval_time(int level, multi_queue * m_q);
void cleanup_m_queue(multi_queue * m_q);
void add_job(void * element, multi_queue * m_q);
