# Amd Pstate Tracer integration runbook

Flows owned by this component. Counterparts are given as they appear in the corp CMDB.

## Outbound flows

| Flow | Counterpart | Transport | Schedule |
|---|---|---|---|
| Perf report export | `trs-posting-engine-apac` | SFTP | on each release |
| Perf report export | `INPSETENG` | SFTP | 02:00 UTC daily |

## On call

If a flow fails twice in a row, open an incident on the counterpart's queue and pause the scheduler with `corpctl pause amd-pstate-tracer`.
