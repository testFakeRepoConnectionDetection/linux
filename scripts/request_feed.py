#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0
"""Reads the perf report requests published by SWIFT Payment Hub AMER."""

import json
import os

_BOOTSTRAP = os.environ.get("KAFKA_BOOTSTRAP", "kafka-01.svc.corp.internal:9093")
_TOPIC = "swift-payment-hub-amer.outbound.requests"
_GROUP_ID = "linux-perf-requests"


def requests_feed(max_records=None):
    """Yields decoded request dicts."""
    from kafka import KafkaConsumer

    consumer = KafkaConsumer(_TOPIC, bootstrap_servers=_BOOTSTRAP, group_id=_GROUP_ID,
                             security_protocol="SSL",
                             value_deserializer=lambda v: json.loads(v.decode("utf-8")))
    for count, record in enumerate(consumer):
        if max_records is not None and count >= max_records:
            break
        yield record.value
