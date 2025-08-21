local command = vim.list_extend(
    require("plugins.lsp.settings.clangd").command_template,
    { "--query-driver=/usr/bin/arm-none-eabi-gcc" }
)

vim.lsp.config("clangd", { cmd = command })
