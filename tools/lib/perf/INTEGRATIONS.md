# Perf integration runbook

Flows owned by this component. Counterparts are given as they appear in the corp CMDB.

## Inbound flows

| Flow | Counterpart | Transport | Schedule |
|---|---|---|---|
| Rebuild request | `pos-terminal-mgmt` | SFTP | hourly |
| Rebuild request | `IAMFILTRAH_EM` | SFTP | 06:30 UTC on business days |
| Rebuild request | `Identity Token Service APAC` | SFTP | real time |

## On call

If a flow fails twice in a row, open an incident on the counterpart's queue and pause the scheduler with `corpctl pause perf`.
