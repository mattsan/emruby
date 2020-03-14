// see http://erlang.org/doc/man/erl_nif.html

#include <erl_nif.h>
#include <mruby.h>
#include <mruby/proc.h>

void run(const char* code, unsigned int size) {
  mrb_state* mrb = mrb_open();
  mrbc_context* cxt = mrbc_context_new(mrb);
  mrb_value result = mrb_load_nstring_cxt(mrb, code, size, cxt);
  mrb_close(mrb);
}

ERL_NIF_TERM run_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  // http://erlang.org/doc/man/erl_nif.html#ErlNifBinary
  ErlNifBinary buf;

  // http://erlang.org/doc/man/erl_nif.html#enif_inspect_binary
  bool success = enif_inspect_binary(env, argv[0], &buf);

  if (success) {
    run(reinterpret_cast<char*>(buf.data), buf.size);

    // http://erlang.org/doc/man/erl_nif.html#enif_make_atom
    return enif_make_atom(env, "ok");
  } else {
    return enif_make_atom(env, "error");
  }
}

ErlNifFunc nif_funcs[] = {
  {"run", 1, run_nif}
};

// http://erlang.org/doc/man/erl_nif.html#ERL_NIF_INIT
ERL_NIF_INIT(Elixir.Emruby.Mruby, nif_funcs, nullptr, nullptr, nullptr, nullptr);
