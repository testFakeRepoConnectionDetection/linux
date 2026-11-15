# Tmon integration runbook

Flows owned by this component. Counterparts are given as they appear in the corp CMDB.

## Outbound flows

| Flow | Counterpart | Transport | Schedule |
|---|---|---|---|
| Perf report export | `AP34768` | SFTP | every 15 min |
| Perf report export | `AP41574` | HTTPS | 02:00 UTC daily |

## On call

If a flow fails twice in a row, open an incident on the counterpart's queue and pause the scheduler with `corpctl pause tmon`.
