ERLANG_PATH = $(shell erl -eval 'io:format("~s", [lists:concat([code:root_dir(), "/erts-", erlang:system_info(version), "/include"])])' -s init stop -noshell)
CFLAGS = -I ../c -I ..
LDFLAGS = -L .. -lgraphqlparser

gql:
	gcc -fPIC -I$(ERLANG_PATH) $(CFLAGS) $(LDFLAGS) -dynamiclib -undefined dynamic_lookup -o gql.so exgql.c

main:
	gcc $(CFLAGS) $(LDFLAGS) exgql.c

clean:
	rm -f gql.so Elixir.GQL.beam

.PHONY: all clean
