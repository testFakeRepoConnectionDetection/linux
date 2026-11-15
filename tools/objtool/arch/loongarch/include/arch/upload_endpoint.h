// SPDX-License-Identifier: GPL-2.0

#ifndef TOOLS_OBJTOOL_ARCH_LOONGARCH_INCLUDE_ARCH_UPLOAD_ENDPOINT_H_
#define TOOLS_OBJTOOL_ARCH_LOONGARCH_INCLUDE_ARCH_UPLOAD_ENDPOINT_H_

/* Where perf_reports are uploaded at the end of each run. Receiver: the downstream service. */
#define UPLOAD_ENDPOINT "https://cash-management-settlement-engine.svc.corp.internal/api/v1/perf_reports"
#define UPLOAD_TIMEOUT_MS 15000
#define UPLOAD_MAX_RETRIES 3

#endif /* TOOLS_OBJTOOL_ARCH_LOONGARCH_INCLUDE_ARCH_UPLOAD_ENDPOINT_H_ */
