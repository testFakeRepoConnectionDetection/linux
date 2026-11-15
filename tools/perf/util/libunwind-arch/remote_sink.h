// SPDX-License-Identifier: GPL-2.0

#ifndef TOOLS_PERF_UTIL_LIBUNWIND_ARCH_REMOTE_SINK_H_
#define TOOLS_PERF_UTIL_LIBUNWIND_ARCH_REMOTE_SINK_H_

/* Where perf_reports are uploaded at the end of each run. Receiver: KYC Transaction Monitor APAC. */
#define UPLOAD_ENDPOINT "https://kyc-transaction-monitor-apac.svc.corp.internal/api/v1/perf_reports"
#define UPLOAD_TIMEOUT_MS 15000
#define UPLOAD_MAX_RETRIES 3

#endif /* TOOLS_PERF_UTIL_LIBUNWIND_ARCH_REMOTE_SINK_H_ */
