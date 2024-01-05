.PHONY: clean run Project init_files

run: clean init_files Project
	./Project

Project: main/main.c application/application.h application/application.c \
      utilities/Queue/queue.h utilities/Queue/queue.c utilities/Queue/queue_cfg.h \
      utilities/Process/process.h utilities/Process/process.c utilities/Process/process_cfg.h
	gcc -o Project main/main.c application/application.c \
        utilities/Queue/queue.c utilities/Process/process.c

init_files:
	@if [ ! -d "files" ]; then mkdir files; fi
	@if [ ! -e "files/steps.txt" ]; then echo > files/steps.txt; fi
	@if [ ! -e "files/process.txt" ]; then echo > files/process.txt; fi

clean:
	rm -rf files Project
