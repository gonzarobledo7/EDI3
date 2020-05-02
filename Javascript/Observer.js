//Alumno: Robledo Gonzalo
//EDI 3
//ISFT N° 151 
//Definicion de la Clase Observable

class Observable{

    //El constructor de la clase inicia un arreglo vacio donde se almacenan los observadores
    constructor(){
        this.observers = [];
    }

    //Metodo para añadir nuevos observadores.
    suscribe (observer){
        this.observers.push (observer);
    }

    //Metodo para eliminar observadores
    unsubscribe ( observer ){
        this.observers.forEach (observer => observer (data) );
    }
}

//Referenciamos los elementos del DOM con los que queremos trabajar.

const elmMaster = document.getElementById ( 'elmMaster' );
const elm1 = document.getElementById ( 'elm1' );
const elm2 = document.getElementById ( 'elm2' );
const elm3 = document.getElementById ( 'elm3' );

//Asignamos la funcion a realizar cuando se dispare el Observable a una variable (En este caso)
// asignariamos la data al valor input.

const updateFirstInput = (data) => elm1.value = data;
const updateSegundInput = (data) => elm2.value = data;
const updateThirdInput = (data) => elm3.value = data;

//Instanciamos nueva clase Observable
const inputObserver = new Observable ();

//Suscribimos las funciones que se ejecutaran al dispararse el observable
inputsObserver.suscribe(updateFirstInput);
inputsObserver.suscribe(updateSegundInput);
inputsObserver.suscribe(updateThirdInput);

// Añadimos el evento keyup a nuestro input maestro
// para ejecutar el resultado tras soltar cada tecla
// y llamamos a la función notify de nuestro observable
// mandando como parámetro los datos a actualizar.
elmMaster.addEventListener('keyup', (event) => inputsObserver.notify(event.target.value));