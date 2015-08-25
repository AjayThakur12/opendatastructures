CFLAGS=-Wall -Wextra -std=c++11
INCLUDE_PATHS = -I./include

.PHONY spec: clean_spec spec/bin/list_spec.app spec/bin/queue_spec.app

.PHONY clean_spec:
	rm -f spec/bin/*.app

spec/bin/list_spec.app:
	g++ $(CFLAGS) $(INCLUDE_PATHS) spec/src/list_spec.cpp -o spec/bin/list_spec.app

spec/bin/queue_spec.app:
	g++ $(CFLAGS) $(INCLUDE_PATHS) spec/src/queue_spec.cpp -o spec/bin/queue_spec.app

