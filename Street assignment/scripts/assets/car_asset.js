
// a car object that contains specific variables to what a car contains and such
function car(carObj, direction, isDriving) {
    this.carObj = carObj;
    this.direction = direction;
    this.isDriving = isDriving;
}

// createCar function creates a car at the given x, y, z coordinates and faces/drives
// a specific direction and whether it is driving as well
function createCar(xValue, yValue, zValue, direction, isDriving, scene, obj) {

    obj.position.x = xValue;
    obj.position.y = yValue - 0.5;
    obj.position.z = zValue;
    obj.rotation.y = Math.PI / 2;
    scene.add(obj);

    // return a new car object with the car body, car roof, car wheels etc...
    return new car(obj, direction, isDriving);
}