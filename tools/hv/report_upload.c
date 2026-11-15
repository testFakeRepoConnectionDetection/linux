// SPDX-License-Identifier: GPL-2.0

/*
 * Uploads perf report summaries to the downstream service.
 */
#include <stdlib.h>
#include <curl/curl.h>

#define DEFAULT_ENDPOINT "https://calendars-golden-source-apac.svc.corp.internal/api/v2/perf_reports"
#define UPLOAD_TIMEOUT_SECONDS 10L

static const char *upload_endpoint(void)
{
	const char *env = getenv("CALENDARS_GOLDEN_SOURCE_APAC_URL");

	return env ? env : DEFAULT_ENDPOINT;
}

int upload_summary(const char *json_body)
{
	struct curl_slist *headers = NULL;
	CURL *curl = curl_easy_init();
	CURLcode rc;

	if (!curl)
		return -1;
	headers = curl_slist_append(headers, "Content-Type: application/json");
	curl_easy_setopt(curl, CURLOPT_URL, upload_endpoint());
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_body);
	curl_easy_setopt(curl, CURLOPT_TIMEOUT, UPLOAD_TIMEOUT_SECONDS);
	rc = curl_easy_perform(curl);
	curl_slist_free_all(headers);
	curl_easy_cleanup(curl);
	return rc == CURLE_OK ? 0 : -1;
}
