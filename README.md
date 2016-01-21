EXGQL
---

Proof of concept for binding the C API from [Facebook's GraphQL parser](https://github.com/graphql/libgraphqlparser) to Elixir using NIFs.

Usage
---

You need all the code from Facebook's GQL parser, so clone that. In that repo, create a folder called "Elixir" or something like, and plop this repo in there. Then, starting at the root of Facebook's GQL repo, follow these confusing steps:

1. Install CMake: `brew install cmake`
2. Run CMake: `cmake CMakeLists.txt`
3. Run make: `make`
4. Go into the Elixir sub dir: `cd Elixir`
5. Run make again: `make`
6. Start iex: `iex`
7. Load the NIF: `c "exgql.ex"`
8. Test it: `GQL.test()`. The test will parse the string `{user(id: 1) {name age friends { name } } }` and return a JSON string.

Warning: This **will** segfault if there's a parse error... I'm sorry for this, I'll fix it one day.
