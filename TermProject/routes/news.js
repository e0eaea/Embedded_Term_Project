var express = require('express');
var mysql = require('mysql');
var router = express.Router();

var pool = mysql.createPool({
  connectionLimit: 3,
  host: 'localhost',
  user: 'pi',
  database: 'Term_Project',
  password: 'al421s'
});

var location='/';

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

router.post('/',function(req,res,next){
  pool.getConnection(function (err, connection) {

    connection.release();
  });

});

module.exports = router;
