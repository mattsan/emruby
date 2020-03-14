defmodule EmrubyTest do
  use ExUnit.Case
  doctest Emruby

  test "greets the world" do
    assert Emruby.hello() == :world
  end
end
