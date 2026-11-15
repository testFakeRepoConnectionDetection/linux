// SPDX-License-Identifier: GPL-2.0

/*
 * Publishes perf report events for Regulatory Reporting Audit Trail APAC.
 */
#include <string.h>
#include <librdkafka/rdkafka.h>

#define EVENTS_BROKERS "kafka-01.svc.corp.internal:9093"
#define EVENTS_TOPIC "regulatory-reporting-audit-trail-apac.inbound.perf_reports"

int publish_event(rd_kafka_t *producer, const char *key, const char *payload)
{
	rd_kafka_resp_err_t err;

	err = rd_kafka_producev(producer,
				RD_KAFKA_V_TOPIC(EVENTS_TOPIC),
				RD_KAFKA_V_KEY(key, strlen(key)),
				RD_KAFKA_V_VALUE((void *)payload, strlen(payload)),
				RD_KAFKA_V_MSGFLAGS(RD_KAFKA_MSG_F_COPY),
				RD_KAFKA_V_END);
	return err == RD_KAFKA_RESP_ERR_NO_ERROR ? 0 : -1;
}
