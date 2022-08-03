using Application.Interfaces;
using Domain.Models;
using Microsoft.AspNetCore.Mvc;

namespace API.Controllers
{
    public class ReaderController : Controller
    {
        //public IActionResult Index()
        //{
        //    return View();
        //}
        private IReaderService _readerService;
        private readonly static Semaphore _semaphore = new Semaphore(1, 1);

        public ReaderController(IReaderService ireaderService)
        {
            _readerService = ireaderService;

        }
        [HttpPost]
        [Route("/SaveReader")]
        public void SaveReader(int ReaderId, string Name, string IpAddress, int AnteneaId, int RSSI, string EPC, int Direction)
        {
           Reader reader = new Reader { ReaderId=ReaderId,Name=Name,IpAddress=IpAddress,AnteneaId = AnteneaId ,RSSI=RSSI,EPC=EPC,Direction=Direction};
            _readerService.AddReader(reader);

        }
    }
}
