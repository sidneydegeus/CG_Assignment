/*define(['threejs'], function($) {



    return {
        initStreet: function(scene) {
            initStreet(scene);
        }
    }
});*/

//This will be the street.
function initStreet(scene) {
    //Cube and cube3 will be the street for the walkers. (NL: Stoep)
    var cube1Geometry = new THREE.BoxGeometry(93, 0.2, 3.3);
    var cube1Material = new THREE.MeshBasicMaterial({
        map: THREE.ImageUtils.loadTexture('img/wall.jpg')
    });
    var cube1 = new THREE.Mesh(cube1Geometry, cube1Material);
    cube1.position.x = 0;
    cube1.position.y = 0.1;
    cube1.position.z = -6.9;
    scene.add(cube1);

    //This will be the street for the drivers
    var cube2Geometry = new THREE.BoxGeometry(93, 0.1, 6.5);
    var cube2Material = new THREE.MeshBasicMaterial({
        map: THREE.ImageUtils.loadTexture('img/straat.jpg')
    });
    var cube2 = new THREE.Mesh(cube2Geometry, cube2Material);
    cube2.position.x = 0;
    cube2.position.y = 0.1;
    cube2.position.z = -2;
    scene.add(cube2);

    //This will be the street for the walkers (NL: Stoep)
    var cube3Geometry = new THREE.BoxGeometry(93, 0.1, 3.3);
    var cube3Material = new THREE.MeshBasicMaterial({
        map: THREE.ImageUtils.loadTexture('img/wall.jpg')
    });
    var cube3 = new THREE.Mesh(cube3Geometry, cube3Material);
    cube3.position.x = 0;
    cube3.position.y = 0.1;
    cube3.position.z = 2.9;
    scene.add(cube3);
}