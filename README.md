# cuartetoDeNos2

Holi, aca vamos a hacer nuestro TP. Todos vamos a trabajar en la branch: Master para no complicarnos la vida.
Basicamente cuando quieran aportar algo al trabajo va a ser algo asi:
* van a la ubicacion de la carpeta `cuartetoDeNos` usando el comando `cd` en la consola.
* `git pull` para actualizar el trabajo si es que alguien hizo un cambio
* Abren el archivo `main.tex` con el editor de texto que les guste
* Trabajan... hacen cambios...
* Cuando esten felices con lo que agregaron, en la consola hacen `git add *` (Esto prepara los cambios que hicieron para subirlos)
* Luego hacen `git commit -m "(Aqui pongan una breve descripcion del cambio que hicieron)"`. Ej: "hice el ejerc 3"
* Finalmente `git push origin master`. Esto es **permanente**, y se aplicaran los cambios que hicieron al repositorio en GitHub.

Igualmente les recomiento [esta pagina](https://dzone.com/articles/top-20-git-commands-with-examples) que tiene muchos commandos de git con ejemplos por si tienen alguna duda.

### INICIALIZACION
Antes de todo, para empezar tienen que descargar el repositorio en su compu.
Para eso esta el comando `git clone` y luego la direccion URL del repositorio. Asique:
* En la consola pongan `git config –global user.name “name”` y donde dice name pongan su nombre entre "".
* Luego `git config –global user.email “asdf@asdf.com”` con su email entre "".
* Despues usando el comando `cd` vayan a la ubicacion donde quieran que se cree la carpeta del tp.
* Y ponen `git clone https://github.com/sscubino/cuartetoDeNos.git`
* Listo ya crearon la carpeta con el TP donde quisieron.

### Cómo generar analisis de cobertura de código (linux)
Correr en el directorio principal del proyecto:
- `lcov --capture --directory cmake-build-debug/ --output-file cobertura`
- `genhtml cobertura --output-directory html`

(Puede que tengan que instalar lcov, con `sudo apt install lcov`)

Se les va a generar una carpeta "html", pueden abrir el archivo "index.html" con su navegador favorito
