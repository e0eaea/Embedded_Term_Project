var express = require('express');
var router = express.Router();

var location='/';

/* GET home page. */
router.get('/', function(req, res, next) {
	res.redirect("/weather.html");
});
module.exports = router;
