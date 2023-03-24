.name "Conman"
.comment "I barely passed"

load_ammunition:
				ld		%0, r15
				sti		r1, %:keep_alive, %1
				fork	%:keep_alive
				live		%42
				ld		%439025904, r2
				fork	%:build_wall

send_agents:
				live		%42
				fork 	%:load_ammunition
				live		%42
				fork 	%:attack2
				ld		%0, r14
				live		%42
				zjmp	%:attack

build_wall:
				live		%42
				st			r2, -1000
				st			r2, 1000
				st			r2, -1000
				st			r2, 1000
				st			r2, -1000
				st			r2, 1000
				st			r2, -1000
				st			r2, 1000
				st			r2, -1000
				st			r2, 1000
				st			r2, -1000
				st			r2, 1000
				st			r2, -1000
				st			r2, 1000
				st			r2, -1000
				st			r2, 1000
				st			r2, -1000
				st			r2, 1000
				st			r2, -1000
				st			r2, 1000
				st			r2, -1000
				st			r2, 1000
				st			r2, -1000
				st			r2, 1000
				st			r2, -1000
				st			r2, 1000
				st			r2, -1000
				st			r2, 1000
				st			r2, -1000
				st			r2, 1000
				st			r2, -1000
				ld			%0, r14
				zjmp		%:build_wall

keep_alive:
				live		%42
				zjmp		%:keep_alive

attack:
				live		%42
				add			r2, r2, r3
				sti			r3, %500, %:attack2
				sti			r3, %504, %:attack2
				sti			r3, %508, %:attack2
				sti			r3, %512, %:attack2
				sti			r3, %516, %:attack2
				sti			r3, %520, %:attack2
				sti			r3, %524, %:attack2
				sti			r3, %530, %:attack2
				sti			r3, %534, %:attack2
				sti			r3, %538, %:attack2
				sti			r3, %542, %:attack2
				sti			r3, %546, %:attack2
				sti			r3, %550, %:attack2
				sti			r3, %554, %:attack2
				sti			r3, %558, %:attack2
				sti			r3, %562, %:attack2
				sti			r3, %566, %:attack2
				sti			r3, %570, %:attack2
				sti			r3, %574, %:attack2
				sti			r3, %578, %:attack2
				sti			r3, %582, %:attack2
				sti			r3, %586, %:attack2
				sti			r3, %590, %:attack2
				sti			r3, %592, %:attack2
				sti			r3, %596, %:attack2
				sti			r3, %600, %:attack2
				ld			%0, r13
				live		%42
				zjmp		%:attack

attack2:
				sti			r3, %700, %:attack2
				sti			r3, %704, %:attack2
				sti			r3, %708, %:attack2
				sti			r3, %712, %:attack2
				sti			r3, %716, %:attack2
				sti			r3, %720, %:attack2
				sti			r3, %724, %:attack2
				sti			r3, %730, %:attack2
				sti			r3, %734, %:attack2
				sti			r3, %738, %:attack2
				sti			r3, %742, %:attack2
				sti			r3, %746, %:attack2
				sti			r3, %750, %:attack2
				sti			r3, %754, %:attack2
				sti			r3, %758, %:attack2
				sti			r3, %762, %:attack2
				sti			r3, %766, %:attack2
				sti			r3, %770, %:attack2
				sti			r3, %774, %:attack2
				sti			r3, %778, %:attack2
				sti			r3, %782, %:attack2
				sti			r3, %786, %:attack2
				sti			r3, %790, %:attack2
				sti			r3, %792, %:attack2
				sti			r3, %796, %:attack2
				sti			r3, %800, %:attack2
				ld			%0, r13
				live		%42				
				zjmp		%:attack2
				