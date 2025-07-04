# Guia de como uar o Template CMake

## Precisa alterar

Muda o nome do projeto de _Tutorial_ para o nome desejado. Essa mudança será
propagada através da variável `${PROJECT_NAME}`.

## Build system

**Debug**:

```bash
cd debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
```

Atalho do NeoVim `<leader>cD`.

**Release**:

```bash
cd debug
cmake -DCMAKE_BUILD_TYPE=Release ..
```

Atalho do NeoVim `<leader>cR`.

## Compilar

A partir do diretório raiz:

```bash
cmake --build debug
cmake --build release
```

Atalho do NeoVim `<leader>cd` e `<leader>cr`.

## Instalar

A partir do diretório raiz:

```bash
cmake --install release --prefix "installation_path"
```

## Gerar pacote

```bash
cd release
cpack
```

ou

```bash
cd release
cpack -G ZIP
```
