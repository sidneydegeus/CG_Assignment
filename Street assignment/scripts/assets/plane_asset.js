

// initPlane function initiates the plane
function initPlane(scene) {
    var material = new THREE.MeshLambertMaterial({ color : 0x447733 });
    var plane = new THREE.Mesh(new THREE.PlaneGeometry(200, 50), material);
    plane.material.side = THREE.DoubleSide;
    plane.position.x = 0;
    // rotating the plane
    plane.rotation.x = Math.PI / 2;
    scene.add(plane);
    // planeBox will contain the vector3 of the plane, to calculate movements
    // if it will reach the end of the plane
    return new THREE.Box3().setFromObject(plane);
}