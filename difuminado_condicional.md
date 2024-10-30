
def get_i(x, y, max_x, max_y)

calcular inidices de pixeles adyacentes y central:
x_central
y_central
n = n capas adyacentes

lonjitud cuadrado 2 * n + 1

checkear segfault
x_inicial = min(max(x_central - longitud_cuadrado, 0), max_x)
y_inicial = ...

for x = x_inicial; x < x_inicial + lonjitud_cuadrado; x++
	for y = y_inicial; ...
		tienes iteracion para cada cuadrado del difuminado


// a mas variacion mas pequeño es el numero entre 0 y uno incluido
def get_variacion_color:
	n = n capas adyacentes
	cuenta = 0


	inicial = pixel central
	r_inicial
	g_inicial
	b_iniicial

	por cada pixel p en cada capa adyacente y en el central
		tmp = 0
		tmp += r_inicial - r
		tmp += g_inicial - g
		tmp += b_inicial - b
		cuenta += abs(tmp) / (255 * 3)
		
	
	return 1 - cuenta
	
variacion de color = c_var

// Se tiene que hacer para r, g, y b
def get_color_difuminado():
	n = n capas adyacentes
	cuenta = 0
	por cada pixel p y  en las capas adyacentes y en el central:
		por cada r, g y b como color en cada pixel p
			cuenta += color
	cuenta /= len(pixeles en capas adyacentes)
	return cuenta

variacion de color normalizada [0, 1] = c_var_norm
0 (mucha variacion, no se quiere perder detalle)
1 (poca variacion, no importa perder detalle)

para r, g, y b como c (color) en rgb:
	c += (color_difuminado - c) * variacion_color_normalizado