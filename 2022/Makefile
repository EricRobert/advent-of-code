UID=$(shell id -u)

%.run: DAY=$*
%.run: $(DAY)
	@docker run --rm -ti -v $(PWD)/$(DAY):/code -w /code -u $(UID):$(UID) gcc:12 g++ -std=c++20 -O2 main.cpp -o run
	@./test.sh $(DAY)
