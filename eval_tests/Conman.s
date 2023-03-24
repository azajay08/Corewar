.name "Conman"
.comment "I barely passed"

load_ammunition:
				ld		%0, r15
				sti		r1, %:keep_alive, %1
				fork	%:keep_alive
				ld		%439025904, r2
				fork	%:build_wall

send_agents:
				lfork 	%-1365
				lfork	%1365
				lfork	%:load_ammunition
				ld		%0, r14
				zjmp	%:send_agents

build_wall:
	live		%42
	st			r2, -400
	st			r2, 400
	st			r2, -400
	st			r2, 400
	st			r2, -400
	st			r2, 400
	st			r2, -400
	st			r2, 400
	st			r2, -400
	st			r2, 400
	st			r2, -400
	st			r2, 400
	st			r2, -400
	st			r2, 400
	st			r2, -400
	st			r2, 400
	st			r2, -400
	st			r2, 400
	st			r2, -400
	st			r2, 400
	st			r2, -400
	st			r2, 400
	st			r2, -400
	st			r2, 400
	st			r2, -400
	st			r2, 400
	st			r2, -400
	st			r2, 400
	st			r2, -400
	st			r2, 400
	st			r2, -400
	ld			%0, r14
	zjmp		%:build_wall

keep_alive:
				live		%42
				zjmp		%:keep_alive
