CFLAGS=-Wall -Wextra -std=c++11
INCLUDE_PATHS = -I./include

.PHONY spec: clean_spec spec/bin/array_list_spec.app spec/bin/linked_list_spec.app spec/bin/binary_tree_spec.app

.PHONY clean_spec:
	rm -f spec/bin/*.app

spec/bin/array_list_spec.app:
	g++ $(CFLAGS) $(INCLUDE_PATHS) spec/src/array_list_spec.cpp -o spec/bin/array_list_spec.app

spec/bin/linked_list_spec.app:
	g++ $(CFLAGS) $(INCLUDE_PATHS) spec/src/linked_list_spec.cpp -o spec/bin/linked_list_spec.app

spec/bin/binary_tree_spec.app:
	g++ $(CFLAGS) $(INCLUDE_PATHS) spec/src/binary_tree_spec.cpp -o spec/bin/binary_tree_spec.app
