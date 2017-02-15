/*define(['threejs'], function($) {
    var sun;


    return {
        initSun: function(scene) {
            initSun(scene);
        },
        getSun: function() {
            return sun;
        }
    }
});*/

// initSun function initiates the sun
//The sun is a sphere and will be rotating
function initSun(scene) {
    var geometrySphere = new THREE.SphereGeometry(3, 30, 18);
    var materialPhong = new THREE.MeshPhongMaterial({color: 0xff9900, shininess: 100});
    var sun = new THREE.Mesh(geometrySphere, materialPhong);
    sun.position.x = 0;
    sun.position.z = 0;
    sun.position.y = 15;
    scene.add(sun);

    return sun;
}