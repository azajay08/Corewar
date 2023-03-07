.name "add"
.comment "addition"

# add {T_REG, T_REG, T_REG}
ft_label:
			add r1, r2, r3
			add r3, r2, r1
			add r1, r1, r1
			add r15, r16, r1

ft_label2:
