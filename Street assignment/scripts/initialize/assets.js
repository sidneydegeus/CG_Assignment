define([
    'threejs',
    'assets/plane_asset',
    'assets/street_asset',
    'assets/sun_asset',
    'assets/house_asset',
    'assets/car_asset',
    'assets/tree_asset',
    'util/randomizer'
], function($) {

    var cars = [];
    var planeBox;
    var sun;

    function initAssets(scene) {
        planeBox = initPlane(scene);
        sun = initSun(scene);
        initStreet(scene);



        var loader = new THREE.ObjectLoader();
        loader.load("models/camero-2010-low-poly.json",function ( obj ) {
            //Create two driving cars, x, y, z, left/right, isDriving
            cars[0] = createCar(-11, 1, -1, false, true, scene, obj); // true is to the right
        });
        loader.load("models/camero-2010-low-poly.json",function ( obj ) {
            //Create two driving cars, x, y, z, left/right, isDriving
            cars[1] = createCar(11, 1, -1, false, true, scene, obj); // false is to the left
        });

     /*   forLoop(createaRandomCar, scene);*/

    }

/*    function forLoop(callback, scene) {
        //Create houses, starts at x-45 every house +3 x for nice placement
        //It starts at x:-45 because it will start at the edge
        var xPlace = -90;

        //carint, because every car have an own integer it will start at 2 (0, 1 are already driving)
        var carInt = 2;

        for (var i = 0; i < 31; i++) {
            if(i % 3 == 0) {
                //Create trees at two different places. At the front side and the backside
                createTree(xPlace-3, 1, -5.6, scene);
                createTree(xPlace-3, 1, 1.9, scene);

                //If i is lower then 28 it will create a car between the trees. It will be a 50% chance that the car is there.
                //Because sometimes the owner is not home
                if(i < 28) {
                    if(getRandomInt(1,2) == 1) {

                            callback(carInt, xPlace, scene);
                            carInt += 1;

                    }
                    if(getRandomInt(1,2) == 1) {
                            callback(carInt, xPlace, scene);
                            carInt += 1;
                    }
                    if(getRandomInt(1,2) == 1) {

                            callback(carInt, xPlace, scene);
                            carInt += 1;

                    }
                    if(getRandomInt(1,2) == 1) {

                            callback(carInt, xPlace, scene);
                            carInt += 1;

                    }
                    if(getRandomInt(1,2) == 1) {

                            callback(carInt, xPlace, scene);
                            carInt += 1;

                    }
                    if(getRandomInt(1,2) == 1) {
                        callback(carInt, xPlace, scene);
                        carInt += 1;
                    }
                }
            }

            //2 house methods because you need to rotate the house for the front and the back
            createHouse(xPlace, 2, -10.6, false, scene);
            createHouse(xPlace, 2, 6.6, true, scene);

            //Every three x places you want another house
            xPlace += 6;
        }
    }*/

/*    function createaRandomCar(index, xPlace, scene) {
        var loader = new THREE.ObjectLoader();
        loader.load("models/camero-2010-low-poly.json",function ( obj ) {
            //Create two driving cars, x, y, z, left/right, isDriving
            cars[index] = createCar(xPlace + 6, 1, 0.7, false, false, scene); // false is to the left
        });
    }*/

    return {
        initAssets: function(scene) {
            initAssets(scene);
        },
        getCars: function() {
            return cars;
        },
        getPlaneBox: function() {
            return planeBox;
        },
        getSun: function() {
            return sun;
        }
    }
});