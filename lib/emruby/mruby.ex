defmodule Emruby.Mruby do
  @on_load :load_nifs

  def load_nifs do
    :code.priv_dir(:emruby)
    |> Path.join("mruby")
    |> :erlang.load_nif(0)
  end

  def run(_code) do
    raise "NIF has not been loaded"
  end
end
