.PHONY: run test build

BAZEL ?= bazel

run:
	$(BAZEL) run //:main

#test:
#	$(BAZEL) run //src/utils:time_test

test: ## https://google.github.io/googletest/quickstart-bazel.html
	$(BAZEL) test --test_output=all //...

build:
	$(BAZEL) build //...