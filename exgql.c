#include <stdlib.h>
#include <stdio.h>
#include "../c/GraphQLAstNode.h"
#include "../c/GraphQLAstToJSON.h"
#include "../c/GraphQLParser.h"
#include "erl_nif.h"

#define MAXLEN 2056

// Given some text and an error
const char *toJSON(const char *gql_string, const char **error) {
  struct GraphQLAstNode *node;
  node = graphql_parse_string(gql_string, error);
  const char *JSON = graphql_ast_to_json(node);
  return JSON;
}

// int main(int argc, char *argv[]) {
//   char gql_str[MAXLEN] = "{user(id: 1) {name age friends { name } } }";
//   char gql_str2[MAXLEN] = "";
//   const char **err;

//   const char *json = toJSON(gql_str2, err);
//   printf("JSON: %s\n", json);
// }


static ERL_NIF_TERM to_json(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[]) {
  char buf[MAXLEN];
  const char **err;

  // Get the string from Elixir land
  if (!enif_get_string(env, argv[0], buf, MAXLEN, ERL_NIF_LATIN1)) {
    return enif_make_badarg(env);
  }

  const char *ex_json = toJSON(buf, err);

  // Return JSON string
  printf("%s\n", ex_json);

  return enif_make_int(env, 0);
  // return enif_make_string(env, ex_json, ERL_NIF_LATIN1);
}

static ErlNifFunc nif_funcs[] = {
  {"to_json", 1, to_json}
};

ERL_NIF_INIT(Elixir.GQL, nif_funcs, NULL, NULL, NULL, NULL)
