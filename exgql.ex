defmodule GQL do
  @on_load :init

  def init() do
    :erlang.load_nif("./gql", 0)
  end

  def to_json(_str) do
    raise "NIF to_json/1 not implemented!"
  end

  def test() do
    to_json('{user(id: 1) {name age friends { name } } }')
  end
end
