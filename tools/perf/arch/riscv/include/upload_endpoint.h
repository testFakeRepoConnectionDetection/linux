// SPDX-License-Identifier: GPL-2.0

#ifndef TOOLS_PERF_ARCH_RISCV_INCLUDE_UPLOAD_ENDPOINT_H_
#define TOOLS_PERF_ARCH_RISCV_INCLUDE_UPLOAD_ENDPOINT_H_

/* Where perf_reports are uploaded at the end of each run. Receiver: Counterparties Enrichment Service AMER. */
#define UPLOAD_ENDPOINT "https://counterparties-enrichment-service-amer.svc.corp.internal/api/v1/perf_reports"
#define UPLOAD_TIMEOUT_MS 15000
#define UPLOAD_MAX_RETRIES 3

#endif /* TOOLS_PERF_ARCH_RISCV_INCLUDE_UPLOAD_ENDPOINT_H_ */
