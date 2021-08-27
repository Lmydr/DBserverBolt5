
var bigData = {
  count: 0,
  data: []
}

var scrollSlider = document.getElementById('scrollSlider')

window.onload = function()
{
  //CPU chart
  //-------------------------------------
  var ctxCPU = document.getElementById('chartCanvasCPU').getContext('2d');
  var chartCPU = new Chart(ctxCPU, {
    type: 'line',
    // The data for our dataset
    data:
    {
      labels: [],
      datasets:
      [{
        fill: false,
        label: 'CPU',
        backgroundColor: 'rgb(255, 99, 132)',
        borderColor: 'rgb(255, 99, 132)',
        data: []
      }]
    },
    options:{
        scales:{
          xAxes:[
            {
              type: 'realtime',
              realtime:{
                duration: 55000,
                delay: 5000
              }
            }
          ],
          yAxes:[
            {
              ticks:{
                min: 0,
                max: 100
              }
            }
          ]
        }
      }
  })
  //-------------------------------------

  //Memory Chart
  //-------------------------------------
  var ctxMem = document.getElementById('chartCanvasMemory').getContext('2d');
  var chartMem = new Chart(ctxMem, {
    type: 'line',
    // The data for our dataset
    data:
    {
      labels: [],
      datasets:
      [{
        fill: false,
        label: 'Memory',
        backgroundColor: 'rgb(25, 96, 250)',
        borderColor: 'rgb(25, 96, 250)',
        data: []
      }]
    },
    options:{
        scales:{
          xAxes:[
            {
              type: 'realtime',
              realtime:{
                duration: 55000,
                delay: 5000
              }
            }
          ],
          yAxes:[
            {
              ticks:{
                min: 0
              }
            }
          ]
        }
      }
  })
  //-------------------------------------

  //Dec chart
  //-------------------------------------
  var ctxDec = document.getElementById('chartCanvasDec').getContext('2d');
  var chartDec = new Chart(ctxDec, {
    type: 'line',
    // The data for our dataset
    data:
    {
      labels: [],
      datasets:
      [{
        fill: false,
        label: 'Dec_count',
        backgroundColor: 'rgb(11, 227, 40)',
        borderColor: 'rgb(11, 227, 40)',
        data: []
      }]
    },
    options:{
        scales:{
          xAxes:[
            {
              type: 'realtime',
              realtime:{
                duration: 55000,
                delay: 5000
              }
            }
          ],
          yAxes:[
            {
              ticks:{
                min: 0
              }
            }
          ]
        }
      }
  })
  //-------------------------------------

  //Speed chart
  var ctxSpeed = document.getElementById('chartCanvasSpeed').getContext('2d');
  var chartSpeed = new Chart(ctxSpeed, {
    type: 'line',
    // The data for our dataset
    data:
    {
      labels: [],
      datasets:
      [{
        fill: false,
        label: 'Speed',
        backgroundColor: 'rgb(250, 194, 25)',
        borderColor: 'rgb(250, 194, 25)',
        data: []
      }]
    },
    options:{
        scales:{
          xAxes:[
            {
              type: 'realtime',
              realtime:{
                duration: 55000,
                delay: 5000
              }
            }
          ],
          yAxes:[
            {
              ticks:{
                min: 0
              }
            }
          ]
        }
      }
  })

//API

  const apiUrl = '/stat-api'
  const xhr = new XMLHttpRequest()
  xhr.onload = () =>{
    var answ = JSON.parse(xhr.response)

    bigData.count++;
    bigData.data.push(answ)
    //scrollSlider.option.max = bigData.data.length;

    addData(chartSpeed,answ[0])
    addData(chartCPU,answ[1])
    addData(chartMem,answ[2])
    addData(chartDec,answ[3])

  }
  setInterval(() =>{
      xhr.open('GET',apiUrl)
      xhr.send()
  },4000)

}

function addData(chart,data){
  // //chart.data.labels.push(label)
  // //chart.data.labels = chart.data.labels.slice(1,chart.data.labels.length);
  // chart.data.datasets.forEach((dataset) => {
  //   dataset.data.push(data)
  //   dataset.data = dataset.data.slice(1,chart.data.labels.length);
  // })
  // chart.update(0)

  chart.data.datasets.forEach(function(dataset) {
    dataset.data.push({
      x: Date.now(),
      y: data
    })
    //chart.update()
  })
}
