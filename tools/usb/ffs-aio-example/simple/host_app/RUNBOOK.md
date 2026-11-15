# Host App integration runbook

Flows owned by this component. Counterparts are given as they appear in the corp CMDB.

## Outbound flows

| Flow | Counterpart | Transport | Schedule |
|---|---|---|---|
| Perf report export | `CAXASSSER` | HTTPS | real time |
| Perf report export | `msg-notification-service-emea` | SFTP | 06:30 UTC on business days |

## Inbound flows

| Flow | Counterpart | Transport | Schedule |
|---|---|---|---|
| Rebuild request | `aml-rules-engine-apac` | KAFKA | 02:00 UTC daily |

## On call

If a flow fails twice in a row, open an incident on the counterpart's queue and pause the scheduler with `corpctl pause host-app`.
