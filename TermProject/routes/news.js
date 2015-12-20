var express = require('express');
var mysql = require('mysql');
var router = express.Router();

var pool = mysql.createPool({
  connectionLimit: 3,
  host: '172.20.10.6',
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

  var b1=(req.body.button1)?1:0;
  var b2=(req.body.button2)?1:0;
  var b3=(req.body.button3)?1:0;
  var b4=(req.body.button4)?1:0;

 console.log("확인 "+b1+" "+b2+" "+b3+" "+b4);

});

module.exports = router;
