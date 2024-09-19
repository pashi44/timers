#ifndef __QUEUESH__
#define __QUEUES__
#include "tim.h"

//  balking is  called when an  data item is not queued just because of somr consideration
//  reneging : can a data item cancel its membership in the queue

extern s_udp_socket queuedata;
#define QUEUE_DEPTH 10

static uint8_t queueArray[QUEUE_DEPTH * sizeof(s_udp_socket)];
static StaticQueue_t qobj;

static QueueHandle_t qh;

static BaseType_t rc;

#endif
