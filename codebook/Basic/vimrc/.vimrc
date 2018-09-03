set et nu cin ls=2 ts=4 sw=4 sts=4
syntax on

nn <F4> :w! date > %<.pt; cat -n % > %<.pt; lpr %<.pt <CR>
nn <F7> :w <bar> :!~/.script addin %< <CR>
nn <F8> :w <bar> :!~/.script %:e %< <CR>
