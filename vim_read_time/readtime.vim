let g:wpm = 200
" avg words/min = 200, can personalize this


" function to set personal wpm
function! SetWPM(num)
	let g:wpm = a:num
endfunction

" function to calculate read time
function! Readtime()
	let wordcount = 0
    	let lines = getline(1, '$')

    	for l in lines
        	let linewc = len(split(l))
        	let wordcount += linewc
    	endfor

	" * 1.0 to force float math
    	let mins = wordcount * 1.0 / g:wpm

	echo "estimated reading time: " . mins . " minutes"
endfunction

command! Readtime call Readtime() " ex   :Readtime
command! -nargs=1 SetWPM call SetWPM(<args>) " ex  :SetWPM 400

"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣦⣶⣶⣶⣦⣄⡀⠀⠀⠀⠀
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀
"⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀
"⠀⠀⠀⢀⡀⠀⠀⠀⣿⣿⣿⡇⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢷
"⠀⠀⠀⢸⣿⠿⢷⠀⠃⠻⢿⠓⠀⠀⠐⠮⠹⢿⠛⣿⣿⣿⠀
"⠀⠀⠀⢸⣿⠀⢸⠀⠀⠀⠘⡀⠀⠀⠀⢰⣕⣟⣠⣿⣿⣿⠀
"⠀⠀⠀⢸⣿⣤⣾⣄⡀⠀⠚⠻⠆⠥⣤⣿⣟⣿⢿⠟⠃⠉
"⠀⠀⠀⠙⢿⡟⢹⣿⣞⣄⠀⠀⢀⠴⠿⢏⡀⠁⡠⠑⢄
