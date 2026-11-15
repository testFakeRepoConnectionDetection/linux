// SPDX-License-Identifier: GPL-2.0

/*
 * Reads the perf report requests published by KYC Case Manager AMER.
 */
#include <librdkafka/rdkafka.h>

#define REQUESTS_BROKERS "kafka-01.svc.corp.internal:9093"
#define REQUESTS_TOPIC "kyc-case-manager-amer.outbound.requests"
#define REQUESTS_GROUP "linux-perf-requests"

int subscribe_requests(rd_kafka_t *consumer)
{
	rd_kafka_topic_partition_list_t *topics = rd_kafka_topic_partition_list_new(1);
	rd_kafka_resp_err_t err;

	rd_kafka_topic_partition_list_add(topics, REQUESTS_TOPIC, RD_KAFKA_PARTITION_UA);
	err = rd_kafka_subscribe(consumer, topics);
	rd_kafka_topic_partition_list_destroy(topics);
	return err == RD_KAFKA_RESP_ERR_NO_ERROR ? 0 : -1;
}
