.PHONY: run test

run:
	bazel run //:main

test:
	bazel run //src/utils:time_test