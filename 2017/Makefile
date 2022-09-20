aoc:
	docker run --rm -v $(PWD):/aoc -w /aoc golang:1.10 /bin/bash -c "go test ./... && GOOS=$(shell uname | tr A-Z a-z) go build"

.PHONY: aoc