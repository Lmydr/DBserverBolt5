
var ctx = document.getElementById('chartCanvas').getContext('2d');
var chart = new Chart(ctx, {
    // The type of chart we want to create
    type: 'line',

    labels: ['20:20:15', '20:20:20', '20:20:25', '20:20:30', '20:20:35', '20:20:40', '20:20:45'],
    // The data for our dataset
    data: {
        datasets: [{
            fill: false,
            label: 'My First dataset',
            backgroundColor: 'rgb(255, 99, 132)',
            borderColor: 'rgb(255, 99, 132)',
            data: [0, 10, 5, 2, 20, 30, 45]
        },
        {
            fill: false,
            label: 'My First dataset',
            backgroundColor: 'rgb(123, 99, 132)',
            borderColor: 'rgb(123, 99, 132)',
            data: [0, 5, 10, 15, 90, 31, 20]
        }]
    },

    // Configuration options go here
    options: {}
});

function addData(chart,label,data){
  chart.labels.push(label);
  chart.datasets.forEach((dataset) => {
    dataset.push(data);
  });
  chart.update();
}

const apiUrl = '/stat-api';

const xhr = new XMLHttpRequest();

xhr.onload() = () =>{
  addData(chart,'test',88);
}

xhr.open('get',apiUrl);
