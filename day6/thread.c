#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sqlite3.h>

#define THREAD_POOL_SIZE 4

pthread_t pool[THREAD_POOL_SIZE];
int busy[THREAD_POOL_SIZE] = {0};

void *worker(void *arg)
{
    int idx = *(int *)arg;
    free(arg);

    busy[idx] = 1;
    printf("[Thread %d] Working...\n",idx);
    sleep(1);
    busy[idx] = 0;
    return NULL;
}

int main(void)
{
    for (int i = 0;i < THREAD_POOL_SIZE;i++) {
        int *idx = malloc(sizeof(int));
        *idx = i;
        pthread_create(&pool[i],NULL,worker,idx);
    }

    for (int i = 0;i < THREAD_POOL_SIZE;i++) {
        pthread_join(pool[i],NULL);
    }

    printf("All threads finished.\n");

    sqlite3 *db;
    int rc = sqlite3_open(":memory:",&db);
    if (rc != SQLITE_OK) {
        fprintf(stderr,"Cannot open database: %s\n ",sqlite3_errmsg(db));
        return 1;
    }

    const char *sql = "CREATE TABLE test (id INTEGER PRIMARY KEY,name TEXT);";
    rc = sqlite3_exec(db,sql,NULL,NULL,NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr,"SQL error:%s\n",sqlite3_errmsg(db));
        return 1;
    }

    sqlite3_close(db);
    printf("SQLite OK.\n");

    return 0;
}