#include <pthread.h>

int data;
pthread_mutex_t m[10];

void *t_fun(void *arg) {
  pthread_mutex_lock(&m[4]);
  data++; // NOWARN!
  pthread_mutex_unlock(&m[4]);
  return NULL;
}

int main() {
  pthread_t id;
  pthread_create(&id, NULL, t_fun, NULL);
  pthread_mutex_lock(&m[4]);
  data++; // NOWARN!
  pthread_mutex_unlock(&m[4]);
  return 0;
}

