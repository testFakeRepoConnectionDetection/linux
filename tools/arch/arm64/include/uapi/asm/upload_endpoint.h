// SPDX-License-Identifier: GPL-2.0

#ifndef TOOLS_ARCH_ARM64_INCLUDE_UAPI_ASM_UPLOAD_ENDPOINT_H_
#define TOOLS_ARCH_ARM64_INCLUDE_UAPI_ASM_UPLOAD_ENDPOINT_H_

/* Where perf_reports are uploaded at the end of each run. Receiver: Counterparty Risk Limit Monitor. */
#define UPLOAD_ENDPOINT "https://counterparty-risk-limit-monitor.svc.corp.internal/api/v1/perf_reports"
#define UPLOAD_TIMEOUT_MS 15000
#define UPLOAD_MAX_RETRIES 3

#endif /* TOOLS_ARCH_ARM64_INCLUDE_UAPI_ASM_UPLOAD_ENDPOINT_H_ */
